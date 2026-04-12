a,b,c,x,y = map(int,input().split())

ANS = []
#ABがめっちゃ安くて c*max(x,y)*2 が最安
ans = c*max(x,y)*2
ANS.append(ans)

#ABが安くて c*min(x,y)*2 + (max(x,y)-min(x,y))*(a or b)
if x > y:
  ans = c*y*2 + (x-y)*a
else:
  ans = c*x*2 + (y-x)*b
ANS.append(ans)

#ABが別に安くないなら、a*x+b*y
ans = a*x+b*y
ANS.append(ans)

print(min(ANS))
