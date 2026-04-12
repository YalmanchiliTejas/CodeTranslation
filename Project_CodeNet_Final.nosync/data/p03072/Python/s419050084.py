

def main(n, l):
    h = list(map(int, l.split(' ')))
    counter = 0
    max_h = 0
    for i in range(n):
        if max_h <= h[i]:
            counter += 1
            max_h = h[i]
    print(counter)
    
if __name__ == '__main__':
    try:
        n = int(input().strip())
        l = input().strip()
        main(n, l)
    except EOFError:
        pass
