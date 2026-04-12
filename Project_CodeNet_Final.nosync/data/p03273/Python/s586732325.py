h,w = map(int,input().split())
a = [list(input()) for i in range(h)]
l = ["."]*w
while l in a:
  a.remove(l)
  
for j in range(w):
    s = 0
    for m in a:
        if m[j]=="#":
            s = 1
            break
    if s == 0:
        for m in a:
            m[j]=""
for i in a:
    print("".join(i))