def main(N, X, M):
    kurikaesi = []
    shoki = [X]
    st_shoki = {X}

    now = X
    for n in range(1, N):
        next = (now ** 2) % M
        if next in st_shoki:
            i = shoki.index(next)
            kurikaesi = shoki[i:]
            shoki = shoki[:i]
            break
        else:
            shoki.append(next)
            st_shoki.add(next)
            now = next
    else:
        print(sum(shoki))
        exit()

    shou = (N - len(shoki)) // len(kurikaesi)
    amari = (N - len(shoki)) % len(kurikaesi)

    print(sum(shoki) + sum(kurikaesi) * shou + sum(kurikaesi[:amari]))
    
if __name__ == '__main__':
    N, X, M = list(map(int, input().split()))
    main(N, X, M)