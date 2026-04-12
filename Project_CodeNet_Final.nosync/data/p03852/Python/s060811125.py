def main():
    c = input()
    if c in "aeiou":
        return "vowel"
    return "consonant"

if __name__ == '__main__':
    print(main())