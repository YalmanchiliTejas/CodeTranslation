a,b,c,x,y = map(int, input().split())

ans = 0
if a > 2*c and x > 0: # aの価格がcの2倍以上ならx枚のピザをc円のピザで満たす
  ans += x*2*c
  y -= x
  x = 0
if b > 2*c and y > 0: # bの価格がcの2倍以上ならy枚のピザをc円のピザで満たす
  ans += y*2*c
  x -= y
  y = 0
if a+b >= 2*c and x > 0 and y > 0: # a+bの価格がcの2倍以上ならmin(x,y)枚のピザをc円のピザで満たす
  ans += 2*c*min(x,y)
  if x < y:
    y -= x
    x = 0
  elif y < x:
    x -= y
    y = 0
  else:
    x,y = 0,0
# 残りは普通に計算
if x > 0: ans += x*a
if y > 0: ans += y*b
print(ans)