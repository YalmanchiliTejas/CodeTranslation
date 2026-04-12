
import math 

repo = list(map(int, input().split()))

a_kane = repo[0]
b_kane = repo[1]
c_kane = repo[2]
a_maisu = repo[3]
b_maisu = repo[4]
kingaku = 0

test_kane_tantai = 0
test_kane_harf = 0

tantai_kane = a_kane + b_kane
harf_kane = c_kane*2

kaburi_maisu = abs(a_maisu-b_maisu)


if(tantai_kane<harf_kane): #A,Bでシンプルに買った方がいい
    kingaku = a_kane*a_maisu + b_kane*b_maisu
else: #Cで買った方がいい
    if(a_maisu>b_maisu):
        sabun_maisu = a_maisu-b_maisu
        kaburi_maisu = b_maisu
        kingaku += kaburi_maisu*c_kane*2
        test_kane_tantai = sabun_maisu*a_kane
        test_kane_harf = sabun_maisu*c_kane*2
        if(test_kane_tantai>test_kane_harf):
            kingaku += test_kane_harf
        else:
            kingaku += test_kane_tantai
    else:
        sabun_maisu = b_maisu-a_maisu
        kaburi_maisu = a_maisu
        kingaku += kaburi_maisu*c_kane*2
        test_kane_tantai = sabun_maisu*b_kane
        test_kane_harf = sabun_maisu*c_kane*2
        if(test_kane_tantai>test_kane_harf):
            kingaku += test_kane_harf
        else:
            kingaku += test_kane_tantai

print(kingaku)