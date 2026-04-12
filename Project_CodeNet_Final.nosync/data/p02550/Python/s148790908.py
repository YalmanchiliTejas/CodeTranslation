def solve():
    N, X, M = map(int,input().split())
    past_a = {X}
    A = [X]
    ans = prev = X
    for i in range(1, min(M,N)):
        next_a = prev ** 2 % M
        if next_a in past_a:
            loop_start = A.index(next_a)
            loop_end = i
            loop_size = loop_end - loop_start
            loop_elem = A[loop_start:loop_end]

            rest_n = N-i
            ans += rest_n // loop_size * sum(loop_elem)
            ans += sum(loop_elem[:rest_n%loop_size])
            break

        ans += next_a
        past_a.add(next_a)
        A.append(next_a)
        prev = next_a
    
    print(ans)
    
if __name__ == '__main__':
    solve()