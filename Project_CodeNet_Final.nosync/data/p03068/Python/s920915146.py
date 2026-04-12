n=int(input())
s=input()
k=int(input())
for ss in s:
    print(ss if ss==s[k-1] else "*",end="")