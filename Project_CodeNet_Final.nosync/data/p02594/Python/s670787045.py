def check_temp(n: int) -> str:
    return 'Yes' if n >= 30 else 'No'


if __name__ == '__main__':
    print(check_temp(int(input())))