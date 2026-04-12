def make_num(n, k):
    if k == 0 or len(n)<k:
        return 0
    else:
        if int(n[0]) == 0:
            return make_num(n[1:], k)
        else:
            ln = len(n)
            if k == 3:
                return (((ln-1)*(ln-2)*(ln-3))//6)*(9**3) + (int(n[0])-1)*81*(((ln-1)*(ln-2))//2) + make_num(n[1:], k-1)
            elif k == 2:
                return (((ln-1)*(ln-2))//2)*81 + (int(n[0])-1)*9*(ln-1)  + make_num(n[1:], k-1)
            elif k == 1:
                return 9 * (ln-1) + int(n[0])

n = list(input())
k = int(input())

print(make_num(n,k))