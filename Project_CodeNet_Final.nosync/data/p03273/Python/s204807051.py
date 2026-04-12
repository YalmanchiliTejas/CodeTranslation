h,w=map(int,input().split())
a=[]
b=[]
for i in range(h):
   n=input()
   if n.count(".")<w:a+=[n]
for i in range(w):
   if [I[i] for I in a].count(".")==len(a):
      b+=[i]
for i in range(len(a)):
   print("".join([a[i][I] for I in range(w) if I not in b]))