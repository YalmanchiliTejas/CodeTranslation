
def updiv(x,y):
    if x % y == 0:
        return x // y
    else:
        return x // y + 1

def want(K):

    for i in range(N):

        num = 0
        kai = N * K + i
        
        for j in range(N):
            num += max(0 , updiv( a[j] + kai - (N-1) , N + 1))

        #print (kai,num)
        if num <= kai:
            return kai

    return None

N = int(input())

a = list(map(int,input().split()))

l = -1
r = sum(a)

while r-l != 1:

    m = (l+r)//2

    ind = want(m)

    if ind == None:
        l = m
    else:
        r = m

    #print (l,r)

print (want(r))
