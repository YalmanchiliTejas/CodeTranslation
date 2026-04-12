a,b,c,d,e=map(int,input().split())
ret = 10**18
for i in range(max(d,e)+1):
  cnt = 2*i*c
  cnt += max(d-i,0)*a
  cnt+= max(0,e-i)*b
  ret=min(ret,cnt)
print(ret)