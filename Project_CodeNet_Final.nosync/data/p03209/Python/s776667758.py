N, X = map(int, input().split(' '))
length = [1]
patty = [1]
p_before = 1
before = 1
for i in range(N):
    before = before*2+3
    length.append(before)
    p_before = 2*p_before+1
    patty.append(p_before)

def search(n,i):
    if i==0:
        return 1
    if 1<n<length[i-1]+2:
        return search(n-1, i-1)
    elif length[i-1]+2<n<2*length[i-1]+3:
        return patty[i-1]+1+search(n-2-length[i-1],i-1)
    elif n == 1:
        return 0
    elif n ==length[i-1]+2:
        return patty[i-1]+1
    elif n == 2*length[i-1]+3:
        return 2*patty[i-1]+1

print(search(X,N))
