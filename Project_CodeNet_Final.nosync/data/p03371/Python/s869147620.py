A,B,C,X,Y = map(int,input().split())
ans = float('inf')
for i in range(0,2*max(X+1,Y+1)):
    cnt = 0
    a = X - i//2
    b = Y - i//2
    if a<=0:
      a = 0
    if b<= 0:
      b =0
      
    cnt += (a)*A + C*i+(b)*B
    ans  = min(ans,cnt)
print(ans)