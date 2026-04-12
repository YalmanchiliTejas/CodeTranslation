def main():
    N,X,M = map(int,input().split())
    A = X
    ans = A
    LIST = [A]
    C = 0
    flag = False
    for n in range(N-1):
        A = (A**2)%M
        if A in LIST:
            ind = LIST.index(A)
            C = sum(LIST[:ind])
            LIST = LIST[ind:]
            flag = True
            break
        else:
            LIST.append(A)
        ans += A
    else:
        print(ans)
        
    if flag:
        ANS = [0]
        S = 0
        for L in LIST:
            S += L
            ANS.append(S)
            
        a = (N - ind) // len(LIST)
        b = (N - ind) % len(LIST)
        ans = sum(LIST)*a + ANS[b] + C
        
        print(ans)
    
if __name__ == '__main__':
    main()