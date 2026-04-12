n = int(input())
s = list(input())
k = int(input())
var = s[k-1]
ans = ["*" if i != var else i for i in s]

for i in range(len(ans)):
    print(ans[i],end='')
