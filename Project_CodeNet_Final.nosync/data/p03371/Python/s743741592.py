a, b, c, x, y = list(map(int, input().split()))

ans = 0
for i in range(0, max(x,y)+1):
    s = a*max(0,x-i)+b*max(0,y-i)+c*2*i
    if ans == 0:
      ans = s
    else:
      ans = min(ans,s)
    
print(ans)