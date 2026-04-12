# coding: utf-8
s=input()
flg=False
for i in range(len(s)-1):
    if s[i]=="A" and s[i+1]=="C":
        flg=True
if flg:
    print("Yes")
else:
    print("No")