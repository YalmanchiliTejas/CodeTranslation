#include<iostream>
#include<cstdio>
int main(void) {
    int age;
    std::cin>>age;
    if(age == 3 || age == 5 || age== 7)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}