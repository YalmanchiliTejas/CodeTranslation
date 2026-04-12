h,w=map(int,input().split())

x=[input() for _ in range(h)]
y=[x[i] for i in range(h) if '#'in x[i]]
      
c=[]
for i in range(len(y)):
      for j in range(w):
            if y[i][j]=='#':
                  c.append(j)
d=list(set(c))
z=[]
for i in range(len(y)):
      w=[]
      for j in d:
            w.append(y[i][j])
      z.append(w)

for i in range(len(z)):
      print(''.join(z[i]))