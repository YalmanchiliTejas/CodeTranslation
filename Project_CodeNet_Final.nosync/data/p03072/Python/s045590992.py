n, h = int(input()), [int(x) for x in (input().split())]
c,m = 0, 0;

for x in (range(n)):
   if (m <= h[x]):
      m,c = h[x],c+1

print(c)
