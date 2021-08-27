#include <bits/stdc++.h>
using namespace std;

int findPostLength(string subStr, string suffix);
string calculateScore(string text, string prefix, string suffix);
int findPreLength(string subStr, string prefix);

int findPreLength(string subStr, string prefix) {
        int max = 0;
        for (int i = 1; i < subStr.length() + 1; i++) {
            int len = 0;
            int j = prefix.length() - 1;
            string str = subStr.substr(0, i);
            int k =str.length() - 1;

            for (; j >= 0 && k >=0; j--, k--) {
                if (str[k] == prefix[j])
                    len++;
                else
                    break;
            }
            if (len > max && k == -1)
                max = len;
        }
        return max;
    }

int findPostLength(string subStr, string suffix)
{
    int max = 0;
        for (int i = 0; i < subStr.length(); i++) {
            int len = 0;
            string str = subStr.substr(i);
            int k =0;
            for (int j = 0; j <suffix.length() && k < str.length(); j++, k++) {
                if (str[k] == suffix[j])
                    len++;
                else
                    break;
            }
            if (len > max && k == str.length())
                max = len;
        }
        return max;
}

string calculateScore(string text, string prefix, string suffix)
{
    int max = 0;
    int max_pre  = 0;
    string result = "";

    for (int i = 0; i < text.length(); i++) {
            for (int j = i + 1; j <= text.length(); j++) {
                string subStr = text.substr(i, j);
                int pre = findPreLength(subStr, prefix);

                int post = findPostLength(subStr, suffix);

                if(max < (pre + post)) {
                    max = pre + post;
                    result = subStr;
                    max_pre = pre;
                }
                else if(max == pre + post){
                    if(pre > max_pre) {
                        max_pre = pre;
                        result = subStr;
                    }
                    else{
                        string arr[2] = {result,subStr};
                        sort(arr,arr + 2);
                        if(arr[0] == subStr){
                            result = subStr;
                            max_pre = pre;
                        }
                    }
                }
            }
    }
    return result;
}

int main()
{
    string text ;
    string prefix;
    string suffix ;
    
    cin>>text>>prefix>>suffix;

    string result = calculateScore(text, prefix, suffix);
    cout<<result;
}