/////////////////////////////////
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    
    string s="(3+3)+1-11+2";
  class Solution {
public:
    int calculate(string s) {
 
    
    string arr={0};
    int temp=0;
    int register_of_final_result=0;
    int operand=0;
    int power_of_ten=0;
    int sign_before =1;
    int last_sign_of_prackect=1;
  for(int i=0; i<s.size();i++)
       {
       if(s[i]=='+')
             {
                register_of_final_result+=sign_before*operand; 
                sign_before=1;
                operand=0;
                power_of_ten=0;
             }
        else if(s[i]=='-')
                {
                    
                register_of_final_result+=sign_before*operand;
                 sign_before=-1;
                  operand=0;
                power_of_ten=0;  
            }         
      else if (isdigit(s[i]))
           {
                if(power_of_ten>1){
                    power_of_ten-=1; 
                }
                operand=((pow(10,power_of_ten)*operand)+(s[i]-'0'));
                power_of_ten++;
            
         }
      else if(s[i]=='(')
        {
           temp += register_of_final_result ;
            register_of_final_result =0;
            operand=0;power_of_ten=0;
            last_sign_of_prackect=sign_before;
                    
        }
            
    else if(s[i]==')')
         {
             register_of_final_result+=last_sign_of_prackect*sign_before*operand;
            register_of_final_result+= temp ;
            temp=0;     
            operand=0;power_of_ten=0;
            last_sign_of_prackect=1;      
      
         }        
       if(i==s.size()-1)
           {
             register_of_final_result+=sign_before*operand;
            }
    }
  
return register_of_final_result;


    
}
};

cout<<register_of_final_result;;


    return 0;
}
/////////////////////////////////
class Solution1 {
public:
    int calculate(string s) {
        stack<int>st;
        int operand = 0, sign = 1, result = 0;

        for(char ch: s){
            if(isdigit(ch)){
                operand = operand*10 + (ch-'0');
            }else if(ch == '+'){
                result+=sign*operand;
                sign=1;
                operand=0;
            }else if(ch == '-'){
                result+=sign*operand;
                sign=-1;
                operand=0;
            }else if(ch == '('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            }else if(ch == ')'){
                result+=sign*operand;
                operand=0;
                result*=st.top();st.pop(); //for the sign 
                result+=st.top();st.pop(); //for the value
            }
        }
        return result + (sign*operand); //for the last unprocessed part
    }
};
class try_not_correct_all_test_cases_Solution {
public:
    int calculate(string s) {
        int result[100]={0};
         char operation[100]={0};
         int res=0;
         int j=0;
         int  flag_1=0;
         int flag_2=0;
         for(int i =0; i<s.size();i++)
         {
             if (s[i] >= '0' && s[i] <= '9') 
             {
                result[j] = result[j] * 10 + (s[i] - '0');
             }
 

        else if(s[i] == '+' || s[i] == '-' ||s[i] == '(' ||s[i] == ')'  )
             {
                 operation[j]=s[i];
                 j++;
              
             }

         }
           res=result[0];
             for(int i =0; i<j; )
              {
                    if(operation[i]=='+')
                         res +=result[++i];
                    else if(operation[i]=='-')
                         res -=result[++i];
             
                }

        return res;
        
    }
};
