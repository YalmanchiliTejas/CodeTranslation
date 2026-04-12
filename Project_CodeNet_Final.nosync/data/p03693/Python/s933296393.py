def main():
    a, b, c = map(int, input().split())
    print(['NO', 'YES'][(a*100+b*10+c) % 4 == 0])


main()
