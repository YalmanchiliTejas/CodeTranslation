def main():
    S = input()
    d = set()
    for s in S:
        d.add(s)

    if len(d) == 1:
        print('No')
    else:
        print('Yes')
    

main()