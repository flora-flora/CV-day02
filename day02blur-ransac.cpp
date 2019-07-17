//C++ version:
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void medianBlur(vector<vector<int>>& img, vector<vector<int>> kernel, string padding_way) {
	vector<int> tmp;
	int H = img.size();  //获取行数
	int W = img[0].size();  //获取列数
	//边框保留不变
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

RANSAC 伪码
输入：data，model，k(算法的迭代次数)n（最初选择n个点适用于模型）
t（错误率阈值），d(模型适用于数据的个数)out_model,

while (迭代次数 < k)
{
	model_inliner = 从数据集随机选取n个点
	model_par = 初始化适合model_inliner的模型参数
	inliner_set = model_inliner
	for (数据中所有不符合模型的点、外点)
	{
		if (如何适合model_par，且错误率低于t)
			将点添加到model_inliner中
	}
	if (inliner_set点数大于d)
	{
		已经找到好的模型，测试模型错误率
		if (如果当前的错误率低于前一个模型的错误率)
			将当前模型保存
	}
	增加迭代次数
}
最后返回最好的模型
