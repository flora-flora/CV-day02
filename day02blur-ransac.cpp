//C++ version:
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void medianBlur(vector<vector<int>>& img, vector<vector<int>> kernel, string padding_way) {
	vector<int> tmp;
	int H = img.size();  //��ȡ����
	int W = img[0].size();  //��ȡ����
	//�߿�������
	for (int i = 1; i<H - 1; i++)
	{
		for (int j = 1; j<W - 1; j++)
		{
			tmp.push_back(img[i - 1][j - 1]);
			tmp.push_back(img[i - 1][j]);
			tmp.push_back(img[i - 1][j + 1]);
			tmp.push_back(img[i][j - 1]);
			tmp.push_back(img[i][j]);
			tmp.push_back(img[i][j + 1]);
			tmp.push_back(img[i + 1][j - 1]);
			tmp.push_back(img[i + 1][j]);
			tmp.push_back(img[i + 1][j + 1]);
			sort(tmp.begin(), tmp.end());
			int len = tmp.size();
			img[i][j] = tmp[len / 2];
		}
	}
}

RANSAC α��
���룺data��model��k(�㷨�ĵ�������)n�����ѡ��n����������ģ�ͣ�
t����������ֵ����d(ģ�����������ݵĸ���)out_model,

while (�������� < k)
{
	model_inliner = �����ݼ����ѡȡn����
	model_par = ��ʼ���ʺ�model_inliner��ģ�Ͳ���
	inliner_set = model_inliner
	for (���������в�����ģ�͵ĵ㡢���)
	{
		if (����ʺ�model_par���Ҵ����ʵ���t)
			������ӵ�model_inliner��
	}
	if (inliner_set��������d)
	{
		�Ѿ��ҵ��õ�ģ�ͣ�����ģ�ʹ�����
		if (�����ǰ�Ĵ����ʵ���ǰһ��ģ�͵Ĵ�����)
			����ǰģ�ͱ���
	}
	���ӵ�������
}
��󷵻���õ�ģ��
