#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
char s1[2000];
char s2[2000];
int Min(int x, int y, int z)//求最小值函数
{
	int min_data;
	min_data = x;
	if (min_data > y)min_data = y;
	if (min_data > z)min_data = z;
	return min_data;
}
int main()
{
	int k;		//空格固定距离
	cin >> s1 >> s2;
	cin >> k;
	int lenth_s1 = strlen(s1);
	int lenth_s2 = strlen(s2);
	int** dp = new int* [lenth_s1+1];
	for (int i = 0; i <=lenth_s1; i++)
		dp[i] = new int[lenth_s2+1];
	for (int i = 0; i <=lenth_s1; i++)
		dp[i][0] = k * i;
	for (int i = 0; i <= lenth_s2; i++)
		dp[0][i] = k * i;
	for(int i=1;i<=lenth_s1;i++)
		for (int j = 1; j <=lenth_s2; j++)
		{
			dp[i][j] = Min(dp[i - 1][j] + k, dp[i][j - 1] + k, dp[i - 1][j - 1] + abs(s1[i - 1] - s2[j - 1]));
		}
	cout << dp[lenth_s1][lenth_s2];
	return 0;
}