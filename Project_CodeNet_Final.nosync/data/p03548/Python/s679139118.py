def main():
    chair_width, person_width, space = map(int, input().split())
    print((chair_width - space) // (person_width + space))


if __name__ == '__main__':
    main()