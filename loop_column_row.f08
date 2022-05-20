program name
    implicit none
    integer :: i,j
    integer :: n = 1000
    double precision, allocatable :: b(:)
    double precision, allocatable :: x(:)
    double precision, allocatable :: A(:,:)

    real :: startTime, stopTime

    open(1, file = 'loop_column_row_fortran.txt', status='old')  
    do while (n <= 25000)
    
        allocate(b(n),x(n),A(n,n))
        call random_number(x) 
        call random_number(A)

        b = 0

        call cpu_time(startTime)
        do j=1,n
            do i=1,n
                b(i) = b(i) + A(i,j)*x(j)
            end do
        end do

        call cpu_time(stopTime)

        write(1, *) n, (stopTime - startTime)

        deallocate(A,b,x)

        n = n + 1000

    end do
    close(1)
end program name