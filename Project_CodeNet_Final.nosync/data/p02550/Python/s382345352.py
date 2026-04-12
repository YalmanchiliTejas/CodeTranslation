def solve(N,X,M):
    Loop = [X]
    Loop_set = set(Loop)

    for i in range(N):
        X = X**2 % M
        if X not in Loop_set:
            Loop.append(X)
            Loop_set.add(X)
        else:
            break

    loop_st = 0
    for i in range(len(Loop)):
        if Loop[i] == (Loop[-1]**2 % M):
            loop_st = i
            break

    loop_len = len(Loop) - loop_st
    ans = sum(Loop[:loop_st])
    N -= loop_st
    ans += (sum(Loop[loop_st:]) * (N // loop_len) + sum(Loop[loop_st:loop_st + (N % loop_len)]))
    return ans

def main():
    N,X,M = map(int,input().split())

    print(solve(N,X,M))

if __name__ == "__main__":
    main()
