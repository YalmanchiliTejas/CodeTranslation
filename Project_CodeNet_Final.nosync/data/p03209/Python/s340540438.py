N, X = map(int, input().split())

b_p = [2**(i+2)-3 for i in range(N+1)]
p = [2**(i+1)-1 for i in range(N+1)]


def cal_paty(N, X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X <= b_p[N-1] + 1:
        p_num = cal_paty(N-1, X-1)
        return p_num
    else:
        p_num = p[N-1] + 1
        p_num += cal_paty(N-1, X-(2 + b_p[N-1]))
        return p_num

print(cal_paty(N, X))
