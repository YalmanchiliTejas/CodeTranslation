N = [int(i) for i in input()]
n = len(N)
K = int(input())
lis = [0]*3
foo = 0
for i in range(n):
    if N[i]!=0:
        lis[foo] = i
        foo += 1
    if foo==3:
        break



if n < K:
    print(0)
else:
    if K ==3:
        ans = (n-1)*(n-2)*(n-3)*9**3//6
        ans += (N[0]-1)*(n-1)*(n-2)*9**2 //2
        if lis[1]!=0:
            ans += (n-1-lis[1])*(n-2-lis[1])*9**2//2
        if lis[2]!=0:
            ans += (N[lis[1]]-1)*(n-1-lis[1])*9 +(n-1-lis[2])*9 +N[lis[2]]
    elif K ==2:
        ans = (n-1)*(n-2)//2 *9**2 +(N[0]-1)*(n-1)*9
        if lis[1]!=0:
            ans += (n-1-lis[1])*9 +N[lis[1]]
    elif K ==1:
        ans = 9*(n-1) +N[0]

    print(max(0,ans))
