h, w = map(int, input().split())
vec =[]
for i in range(h):
    a = list(input())
    if '#' in a:
        vec.append(a)
    else:
        h -= 1
        
#print(h, w)
#print(vec)


num = []
for i in range(w):
    for j in range(h):
        if vec[j][i] == '#':
            num.append(i)
            break
    
for i in range(h):
    for j in num:
        print(vec[i][j], end='')
    
    print()