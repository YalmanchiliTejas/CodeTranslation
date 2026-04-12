t = list(str(input()).split(" "))
n = int(t[0])
m = int(t[1])

x = [list() for i in range(n)]
lst = list()

for i in range(m):
    t = list(str(input()).split(" "))
    a = int(t[0])
    b = int(t[1])
    x[a-1].append(b-1)
    x[b-1].append(a-1)

def depth(p):

    if(len(lst) == n-1):
        global c
        c = c+1

    else:
        for i in x[p]:
            if(i not in lst):
                lst.append(p)
                depth(i)
                lst.remove(p)

c = 0
depth(0)
print(c)