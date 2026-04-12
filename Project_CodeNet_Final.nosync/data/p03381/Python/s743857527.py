N = int(input())
X = [int(i) for i in input().split()]
ans=[]
Y=sorted(X)
a=Y[N//2 -1]
b=Y[N//2]
for x in X:
    if x<= a:
        ans.append(b)
    else:
        ans.append(a)
print('\n'.join(map(str,ans)))