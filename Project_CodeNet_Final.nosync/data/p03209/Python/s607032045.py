def len_burger(L):
    return 2**(L+2)-3
def num_ban(L):
    return 2**(L+1)-1

def eat(L,X):
    if L == 0: return 1
    if X == 1: return 0
    elif X <= len_burger(L-1)+1: return eat(L-1,X-1)
    elif X == len_burger(L-1)+2: return num_ban(L-1)+1
    elif X < 2*len_burger(L-1)+3: return num_ban(L-1)+1+eat(L-1,X-len_burger(L-1)-2)
    elif X == len_burger(L): return num_ban(L)

def solve():
    N,X = [int(s) for s in input().split() if s]
    
    print(eat(N,X))
    
solve()