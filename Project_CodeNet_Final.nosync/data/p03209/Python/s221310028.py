
def count(ps, N, X):
    if X ==0:
        return 0
    total = ps[N][0]
    #print("count N=%d, x=%-20d, total(N)=%d"%( N, X, total))
    half = (total +1)//2
    if X >= total:
        return ps[N][1]
    elif X < half:
        return count(ps, N-1,X-1)
    elif X == half:
        return ps[N-1][1] + 1
    elif X > half:
        return (ps[N-1][1] + 1) + count(ps, N-1, X - half)


def main(N,X):
    ps = [(1, 1)] # total, p
    for i in range(1, N+1):
        ps.append((ps[i-1][0] * 2 + 3, ps[i-1][1] * 2 + 1))

    c = count(ps, N, X)
    print(c)
    return c

#assert(main(2, 7)== 4)
#assert(main(1,1)==0)
#assert(main(50,4321098765432109)==2160549382716056)
N, X = (int(x) for x in input().split())
main(N, X)




