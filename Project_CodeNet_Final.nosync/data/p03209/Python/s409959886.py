n,x = (int(i) for i in input().split())
lenb = [[1,1,0]]
for i in range(n):
    p = lenb[i][1]*2 + 1
    b = lenb[i][2]*2 + 2
    lenb.append([p+b,p,b])

def count(n,x):
    if n >= 1:
        if x <= 1 + lenb[n-1][0]:
            return count(n-1,x-1)
        elif x ==  1 + lenb[n-1][0] + 1:
            return lenb[n-1][1]+1
        else:
            return lenb[n-1][1]+1 + count(n-1,x-lenb[n-1][0]-2)
    else:
        if x > 0:
            return 1
        else:
            return 0
print(count(n,x))