def main():
    #a, b, c = map(str, input().split())
    a = input()
    if a in ['a', 'i', 'u', 'e', 'o']:
        print('vowel')
        return
    print('consonant')
    return 


if __name__ == '__main__':
    main()
