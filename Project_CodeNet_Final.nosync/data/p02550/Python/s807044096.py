n, x, m =  map(int, input().split())
dic = {}
dic[x]=0
ans = [0]*(10**5+1)
ans[0]=x
a = x

for i in range(1, n):
  a = (a**2) % m
  ans[i]=ans[i-1]+a
  if a in dic:
    kuri = i - dic[a]
    kurisum =ans[i]-ans[dic[a]]
    nokori = n-i
    time = nokori//kuri
    amari = nokori%kuri
    if dic[a] == 0:
      amarisum = ans[amari-1]
    else:
      amarisum = ans[dic[a]-1+amari]-ans[dic[a]-1]
    print(ans[i-1]+amarisum+time*kurisum)
    quit()
  else:
    dic[a]=i
print(ans[n-1])