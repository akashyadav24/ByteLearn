#include<bits/stdc++.h>
using namespace std;
int requiredParentheses(string str) {
   int openingParentheses = 0, closingParentheses = 0;
   for (int i = 0; i < str.length(); ++i) {
      if (str[i] == '(') {
         ++openingParentheses;
      } else if (str[i] == ')') {
         ++closingParentheses;
      }
   }
   return abs(openingParentheses - closingParentheses);
}
int main() {
   string str;
   cin>>str;
   cout  << requiredParentheses(str) << endl;
   return 0;
}