a = int(input())
b = int(input())
def aez(n, k):
    s = str(n)
    ln = len(s)-1
    n1 = int(s[0])
    if len(s) < k:
        return 0
    else:
        if k == 1:
            return 9 * ln + n1 
        elif k == 2:
            return (81 * ln * (ln-1) // 2) + aez(int('9'*ln), 1)*(n1-1) + aez(int(s[1:]), 1)
        else:
            return (729*ln*(ln-1)*(ln-2)//6) + aez(int('9'*ln), 2)*(n1-1) + aez(int(s[1:]), 2)
print(aez(a, b))