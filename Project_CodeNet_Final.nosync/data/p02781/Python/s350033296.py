N= int(input())
K= int(input())

from math import factorial

str_n = str(N)
len_n = len(str(str_n))

def conb(n, r):
    return factorial(n)//factorial(r)//factorial(n-r)
    
def get_num(top, k_val, depth):
    if k_val==0:
        return 1
    elif k_val>(len_n-depth+1):
        return 0
    elif top:
        if int(str_n[depth - 1])==0:
            return get_num(top, k_val, depth + 1)
        else:
            b1 = get_num(top, k_val - 1, depth + 1)
            b2 = (int(str_n[depth-1])-1) * get_num(False, k_val-1, depth+1)
            b3 = get_num(False, k_val, depth + 1)
            return b1+b2+b3
    else:
        return 9**(k_val) * conb(len_n - depth + 1, k_val)
    
    
a1 = get_num(True, K-1, 2)
a2 = (int(str_n[0])-1)*get_num(False, K-1, 2)
a3 = get_num(False, K, 2)

#print(a1, a2, a3)
print(a1+a2+a3)