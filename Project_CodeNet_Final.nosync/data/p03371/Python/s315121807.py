from sys import stdin
A,B,C,X,Y = [int(x) for x in stdin.readline().rstrip().split()]
ans = 10**9
for i in range(0,2*(max(X,Y)+1)):
    total = A*max((X-(i//2)),0) + B*max((Y-(i//2),0)) + i*C
    #print(total,i)
    if total > 0 and total < ans:
        ans = total
print(ans)