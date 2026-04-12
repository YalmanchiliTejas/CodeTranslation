import string

def main():
    n = int(input())
    t = [[0 for _ in range(n)] for _ in string.ascii_lowercase]

    for i in range(n):
        s = input()
        for c in s:
            t[ord(c) - ord('a')][i] += 1
    
    r = []
    for i, c in enumerate(string.ascii_lowercase):
        r.append(c * min(t[i]))
    
    print(''.join(r))

main()
