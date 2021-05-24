#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
//创建点类
class point
{
public:
	double x;			//点的横坐标
	double y;			//点的纵坐标
	point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};
bool CompareX(point a, point b)		//比较横坐标x,如果a<b则返回true
{
	return a.x < b.x;
}
bool CompareY(point a, point b)
{
	return a.y < b.y;
}
double distance(point a, point b)	//计算两个点之间的距离
{
	double dis;
	dis = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	return dis;
}
double min_distance(vector<point> p, int length)//length为这个vector的长度，默认为排好序的
{
	double min_dist = 0.0;
	//如果只有两个点或者三个点则直接暴力求解
	if (length == 2)
	{
		min_dist = distance(p[0], p[1]);
		return min_dist;
	}
	if (length == 3)
	{
		min_dist = distance(p[0], p[1]);
		if (min_dist >= distance(p[1], p[2]))min_dist = distance(p[1], p[2]);
		if (min_dist >= distance(p[0], p[2]))min_dist = distance(p[0], p[2]);
		return min_dist;
	}
	//分治算法
	double min_dist_r = 0;
	double min_dist_l = 0;
	//左右两边最短距离
	vector<point> pl;
	vector<point> pr;			//分为左右两边的vector
	for (int i = 0; i < length / 2; i++)
		pl.push_back(p[i]);
	for (int i =  length / 2; i < length; i++)
		pr.push_back(p[i]);
	//递归求解左右部分的最短距离
	min_dist_r = min_distance(pr, length-length/2);
	min_dist_l = min_distance(pl, length / 2);
	if (min_dist_r >= min_dist_l)min_dist = min_dist_l;
	else
		min_dist = min_dist_r;
	
	double mid = p[length / 2].x;
	vector<point> p_mid;
	double x = min_dist;
	for (int i = 0; i < length; i++)
	{
		if (abs(mid - p[i].x) < min_dist)
			p_mid.push_back(p[i]);
	}
	sort(p_mid.begin(), p_mid.end(), CompareY);//按照y升序排列

	for (int i = 0; i < p_mid.size(); i++)
	{
		vector<point> Parea;
		for (int j = 0; j < p_mid.size(); j++)
		{
			if (abs(p_mid[i].y - p_mid[j].y) < x)
				Parea.push_back(p_mid[j]);
		}
		for(int a=0;a<Parea.size();a++)
			for (int b = a + 1; b < Parea.size(); b++)
			{
				if (min_dist > distance(Parea[a], Parea[b]))
					min_dist = distance(Parea[a], Parea[b]);
			}
	}
	return min_dist;
}
int main()
{
	int num;
	cin >> num;
	vector<point> p;
	double x1, y1;
	for (int i = 0; i < num; i++)
	{
		cin >> x1 >> y1;
		point X(x1, y1);
		p.push_back(X);
	}
	sort(p.begin(), p.end(), CompareX);			//按照x的升序排列
	cout << setiosflags(ios::fixed) << setprecision(2) << min_distance(p, num) * min_distance(p, num);
}

