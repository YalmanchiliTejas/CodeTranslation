#!/usr/bin/env python3
import sys

def convert(ss):
    if ss == 0:
        return "S"
    else:
        return "W"


def solve(N: int, s: str):
    animals = [0]*N
    ## 0 がひつじ 1が狼を表す
    init = [(0,1),(1,0),(0,0),(1,1)]

    for first,second in init:
        animals[0] = first
        animals[1] = second

        for j in range(1,N):
            ## 最後にたどり着いたとき
            if j == N-1:
                if animals[j] == 0:
                    if s[j] == "o":
                        if animals[j-1] != animals[0]:
                            break
                    else:
                       if animals[j-1] == animals[0]:
                            break
                elif animals[j] == 1:
                    if s[j] == "o":
                        if animals[j-1] == animals[0]:
                            break
                    else:
                       if animals[j-1] != animals[0]:
                            break

                if animals[0] == 0:
                    if s[0] == "o":
                        if animals[N-1] != animals[1]:
                            break
                    else:
                       if animals[N-1] == animals[1]:
                            break
                elif animals[0] == 1:
                    if s[0] == "o":
                        if animals[N-1] == animals[1]:
                            break
                    else:
                       if animals[N-1] != animals[1]:
                            break
                
                print(''.join(list(map(convert,animals))))
                return

            if animals[j] == 0:
                if s[j] == "o":
                    animals[j+1] = animals[j-1]
                else:
                    animals[j+1] = 1^animals[j-1]
            elif animals[j] == 1:
                if s[j] == "o":
                    animals[j+1] = 1^animals[j-1]
                else:
                    animals[j+1] = animals[j-1]    

    print(-1)
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    s = next(tokens)  # type: str
    solve(N, s)

if __name__ == '__main__':
    main()
