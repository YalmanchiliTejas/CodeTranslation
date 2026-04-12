def main():
    a, b, c, x, y = map(int, input().split())
    r = float('inf')
    for piza_c in range(0, max(x, y) * 2 + 1, 2):
        piza_a = max(0, x - piza_c // 2)
        piza_b = max(0, y - piza_c // 2)
        r = min(r, piza_c * c + piza_a * a + piza_b * b)
    print(r)

if __name__ == '__main__':
    main()
