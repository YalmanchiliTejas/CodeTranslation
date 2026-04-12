import sys
input = sys.stdin.readline

def main():
    N = int(input())
    S = input()
    for key in ['SS', 'SW', 'WS', 'WW']:
        animals = list(key)
        for i in range(N + 1):
            if i < 1:
                continue
            S_i = S[i] if i < N else S[0]
            if animals[i] == 'S':
                if S_i == 'o':
                    animals += animals[-2]
                else:
                    animals += 'S' if animals[-2] == 'W' else 'W'
            else:
                if S_i == 'x':
                    animals += animals[-2]
                else:
                    animals += 'S' if animals[-2] == 'W' else 'W'
        if animals[0] == animals[-2] and animals[1] == animals[-1]:
            print(''.join(animals[:-2]))
            exit(0)
    print(-1)


if __name__ == '__main__':
    main()

