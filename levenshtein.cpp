#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int leve(string s1, string s2)
{
    int len1 = s1.length(), len2 = s2.length();
 
    int d[len1+1][len2+1];
    
    if(len1==0) return len2;
    if(len2==0) return len1;
    
    for (int i = 0; i <= len1; d[i][0] = i++)
    for (int i = 0; i <= len2; d[0][i] = i++)
    for (int i = 1; i <= len1; i++)
	{
	    for (int j = 1; j <= len2; j++)
	    {
		    int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(min(d[i - 1][j] + 1, d[i][j - 1] + 1),d[i - 1][j - 1] + cost);
	    }
	}
	return d[len1][len2];
}

int main()
{
    string a,b;
    cin>>a;
    cin>>b;
    cout << leve(a,b);
    system("PAUSE");
}





