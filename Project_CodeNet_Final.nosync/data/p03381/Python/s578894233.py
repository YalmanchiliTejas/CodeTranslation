N = input()
X = map(int, raw_input().split())
Y = sorted(X)
c1,c2 = Y[N/2-1],Y[N/2]
for x in X:
  if x<=c1:
    print c2
  else:
    print c1
