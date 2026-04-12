n = int(input())
s = str(input())
k = int(input())
for i in range(n):
    if(s[i] == s[k-1]):
        print(s[i],end="")
    else:
        print("*",end="")