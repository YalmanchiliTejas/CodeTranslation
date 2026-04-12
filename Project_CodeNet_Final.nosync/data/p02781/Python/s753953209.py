import functools
N = int(input())
K = int(input())

@functools.lru_cache(None)
def func(num,counter):
    remain = num%10
    quotient = num//10
    
    
    if counter == 0:
        return 1
    
    if num<10:
        if counter ==1:
            return num
        else:
            return 0

    return func(quotient,counter-1)*remain + func(quotient-1,counter-1)*(9-remain) + func(quotient,counter)

print(func(N,K))