N,X,M = map(int,input().split())

d = {X:0}
l = [X]
s = X

for i in range(1,N):
  l+=[(l[i-1]**2)%M]
  s += l[i]
  if l[i] in d:
    dl = l[d[l[i]]+1:]
    s += sum(dl)*((N-i-1)//len(dl))
    if (N-i-1)%len(dl) != 0:
      s += sum(dl[0:(N-i-1)%len(dl)])
    break
  d[l[i]] = i
print(s)