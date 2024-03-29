#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
   struct stat info;
   if (fstat(STDIN_FILENO, &info) < 0)
   {
      perror("   Error getting info about standard input");
      return -1;
   }
   printf("\n\n   Standard input is owned by user number %d\n", info.st_uid);
   printf("   and was last modified %s\n", ctime(&info.st_mtime));
   if (S_ISREG(info.st_mode))
   {
      // https://linuxopsys.com/topics/inode-in-linux-explained
      printf("   I-node number:          %ld\n", (long)info.st_ino);
      printf("   Mode:                   %lo (octal)\n", (unsigned long)info.st_mode);
      printf("   Link count:             %ld\n", (long)info.st_nlink);
      printf("   User ID:         %ld\n", (long)info.st_uid);
      printf("   Group ID:         %ld\n", (long)info.st_gid);
      printf("   I/O blk size: %ld bytes\n", (long)info.st_size);
      printf("   Size:              %lld bytes\n", (long long)info.st_size);
      printf("   Blocks allocated:       %lld\n", (long long)info.st_nlink);
      printf("   Last status change Timestamp:     %s", ctime(&info.st_ctime));
      printf("   Last access Timestamp:       %s", ctime(&info.st_atime));
      printf("   Last modification Timestamp: %s\n\n\n", ctime(&info.st_mtime));
   }
   else
   {
      printf("   It is not a regular file.\n\n");
   }
   return 0;
}
