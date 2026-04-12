n,x = map(int,input().split())
p=[1]
s=[1]
for i in range(50):
    p.append(p[i]*2+1)
    s.append(s[i]*2+3)

def burger(n,x):
    if n ==0:
        return 1
    elif x == 1:
        return 0
    elif x<=1+s[n-1]:
        return burger(n-1,x-1)
    elif x == 2+s[n-1]:
        return p[n-1] + 1
    elif x <= 2 + s[n-1] * 2:
        return p[n-1] + 1 + burger(n-1,x-s[n-1]-2)
    elif x <= 3 + s[n-1] * 2:
        return 1 + p[n-1] * 2
    else:
        print("ERROR")

print(burger(n,x))