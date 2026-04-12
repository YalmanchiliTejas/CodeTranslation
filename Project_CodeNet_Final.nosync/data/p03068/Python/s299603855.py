n = int(input())
s = input()
k = int(input())
w = s[k-1]
ss = ""
for i in range(n):
    if(s[i] == w):
        ss += w
    else:
        ss += "*"
print(ss)